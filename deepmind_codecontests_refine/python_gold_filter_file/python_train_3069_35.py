w = 0

b = 0
s = ""
for _ in range(8):
  s += input()
w = s.count("Q")*9 + s.count("R")*5 + s.count("B")*3 + s.count("N")*3 + s.count("P")
b = s.count("q")*9 + s.count("r")*5 + s.count("b")*3 + s.count("n")*3 + s.count("p")

if b > w:
  print("Black")
elif w > b:
  print("White")
else:
  print("Draw")
