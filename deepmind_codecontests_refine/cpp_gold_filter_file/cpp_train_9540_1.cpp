#include <bits/stdc++.h>
using namespace std;
struct BaseWidget {
  virtual unsigned long long getWidth() const = 0;
  virtual unsigned long long getHeight() const = 0;
  virtual void setBorder(unsigned){};
  virtual void setSpacing(unsigned){};
  virtual void pack(const BaseWidget *){};
  std::string name_;
  BaseWidget(const std::string &name) : name_(name){};
};
struct Widget : public BaseWidget {
  unsigned width_;
  unsigned height_;
  Widget(const string &name, unsigned width, unsigned height)
      : BaseWidget(name), width_(width), height_(height){};
  unsigned long long getWidth() const { return (unsigned long long)width_; }
  unsigned long long getHeight() const { return (unsigned long long)height_; }
};
struct BoxWidget : public BaseWidget {
  mutable bool counted_;
  vector<const BaseWidget *> widgets_;
  mutable unsigned long long width_;
  mutable unsigned long long height_;
  unsigned border_;
  unsigned spacing_;
  BoxWidget(const std::string &name)
      : BaseWidget(name), counted_(false), border_(0), spacing_(0){};
  void pack(const BaseWidget *w) { widgets_.push_back(w); }
  unsigned long long getWidth() const {
    if (counted_) return width_;
    count();
    counted_ = true;
    return width_;
  }
  unsigned long long getHeight() const {
    if (counted_) return height_;
    count();
    counted_ = true;
    return height_;
  }
  void setBorder(unsigned border) { border_ = border; }
  void setSpacing(unsigned spacing) { spacing_ = spacing; }
  virtual void count() const = 0;
};
struct HBox : public BoxWidget {
  HBox(const std::string &name) : BoxWidget(name){};
  void count() const {
    width_ = 0;
    height_ = 0;
    if (widgets_.size() == 0) return;
    for (size_t i = 0; i < widgets_.size(); ++i) {
      height_ = max(height_, widgets_[i]->getHeight());
      width_ += widgets_[i]->getWidth();
    }
    width_ += 2 * border_;
    height_ += 2 * border_;
    width_ += (widgets_.size() - 1) * spacing_;
  }
};
struct VBox : public BoxWidget {
  VBox(const std::string &name) : BoxWidget(name){};
  void count() const {
    width_ = 0;
    height_ = 0;
    if (widgets_.size() == 0) return;
    for (size_t i = 0; i < widgets_.size(); ++i) {
      width_ = max(width_, widgets_[i]->getWidth());
      height_ += widgets_[i]->getHeight();
    }
    width_ += 2 * border_;
    height_ += 2 * border_;
    height_ += (widgets_.size() - 1) * spacing_;
  }
};
string getString(istream &s, char del) {
  char c;
  string result;
  s.get(c);
  while (c == ' ') s.get(c);
  while (c != del) {
    result += c;
    s.get(c);
  }
  return result;
}
int main(void) {
  map<string, BaseWidget *> widgets;
  int lines;
  cin >> lines;
  string line;
  getline(cin, line);
  while (lines--) {
    getline(cin, line);
    istringstream str(line);
    string order;
    str >> order;
    if (order == "Widget") {
      string name = getString(str, '(');
      char c;
      unsigned width, height;
      str >> width;
      str >> c;
      str >> height;
      widgets[name] = new Widget(name, width, height);
    } else if (order == "VBox" || order == "HBox") {
      string name;
      str >> name;
      if (order == "VBox")
        widgets[name] = new VBox(name);
      else
        widgets[name] = new HBox(name);
    } else {
      str.clear();
      str.str(order);
      string name = getString(str, '.');
      BaseWidget *widget = widgets[name];
      string suborder = getString(str, '(');
      if (suborder == "pack") {
        string subname = getString(str, ')');
        BaseWidget *subwidget = widgets[subname];
        widget->pack(subwidget);
      } else if (suborder == "set_border") {
        unsigned border;
        str >> border;
        widget->setBorder(border);
      } else if (suborder == "set_spacing") {
        unsigned spacing;
        str >> spacing;
        widget->setSpacing(spacing);
      }
    }
  }
  for (map<string, BaseWidget *>::const_iterator it = widgets.begin();
       it != widgets.end(); ++it) {
    cout << it->first << " " << it->second->getWidth() << " "
         << it->second->getHeight() << endl;
  }
  return 0;
}
