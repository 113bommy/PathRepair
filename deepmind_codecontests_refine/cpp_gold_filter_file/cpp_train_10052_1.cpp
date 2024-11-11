#include <bits/stdc++.h>
using namespace std;
template <typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;
template <typename T>
using maxpq = priority_queue<T, vector<T>, less<T>>;
template <typename T1, typename T2, typename H1 = hash<T1>,
          typename H2 = hash<T2>>
struct pair_hash {
  size_t operator()(const pair<T1, T2> &p) const {
    return 31 * H1{}(p.first) + H2{}(p.second);
  }
};
char _inputBuffer[4096 + 1], *_inputPtr = _inputBuffer, _outputBuffer[4096], _c,
                             _sign, *_tempInputBuf = nullptr, _numBuf[128],
                             _tempOutputBuf[128], _fill = ' ';
const char *_delimiter = " ";
int _cur, _outputPtr = 0, _numPtr = 0, _precision = 6, _width = 0,
          _tempOutputPtr = 0, _cnt;
unsigned long long _precisionBase = 1000000;
void read(int &x) {
  do {
    do {
      (x) = (*_inputPtr ? *_inputPtr++
                        : (_inputBuffer[fread(_inputPtr = _inputBuffer, 1, 4096,
                                              stdin)] = '\0',
                           *_inputPtr++));
    } while ((x) <= ' ');
    _sign = (x) == '-';
    if (_sign)
      (x) = (*_inputPtr ? *_inputPtr++
                        : (_inputBuffer[fread(_inputPtr = _inputBuffer, 1, 4096,
                                              stdin)] = '\0',
                           *_inputPtr++));
    for ((x) -= '0';
         (_c = (*_inputPtr ? *_inputPtr++
                           : (_inputBuffer[fread(_inputPtr = _inputBuffer, 1,
                             4096, stdin)] = '\0',
                                   *_inputPtr++))) >= '0';
         (x) = (x)*10 + _c - '0')
      ;
    if (_sign) (x) = -(x);
  } while (0);
}
void read(unsigned int &x) {
  do {
    do {
      (x) = (*_inputPtr ? *_inputPtr++
                        : (_inputBuffer[fread(_inputPtr = _inputBuffer, 1, 4096,
                                              stdin)] = '\0',
                           *_inputPtr++));
    } while ((x) <= ' ');
    _sign = (x) == '-';
    if (_sign)
      (x) = (*_inputPtr ? *_inputPtr++
                        : (_inputBuffer[fread(_inputPtr = _inputBuffer, 1, 4096,
                                              stdin)] = '\0',
                           *_inputPtr++));
    for ((x) -= '0';
         (_c = (*_inputPtr ? *_inputPtr++
                           : (_inputBuffer[fread(_inputPtr = _inputBuffer, 1,
                             4096, stdin)] = '\0',
                                   *_inputPtr++))) >= '0';
         (x) = (x)*10 + _c - '0')
      ;
    if (_sign) (x) = -(x);
  } while (0);
}
void read(long long &x) {
  do {
    do {
      (x) = (*_inputPtr ? *_inputPtr++
                        : (_inputBuffer[fread(_inputPtr = _inputBuffer, 1, 4096,
                                              stdin)] = '\0',
                           *_inputPtr++));
    } while ((x) <= ' ');
    _sign = (x) == '-';
    if (_sign)
      (x) = (*_inputPtr ? *_inputPtr++
                        : (_inputBuffer[fread(_inputPtr = _inputBuffer, 1, 4096,
                                              stdin)] = '\0',
                           *_inputPtr++));
    for ((x) -= '0';
         (_c = (*_inputPtr ? *_inputPtr++
                           : (_inputBuffer[fread(_inputPtr = _inputBuffer, 1,
                             4096, stdin)] = '\0',
                                   *_inputPtr++))) >= '0';
         (x) = (x)*10 + _c - '0')
      ;
    if (_sign) (x) = -(x);
  } while (0);
}
void read(unsigned long long &x) {
  do {
    do {
      (x) = (*_inputPtr ? *_inputPtr++
                        : (_inputBuffer[fread(_inputPtr = _inputBuffer, 1, 4096,
                                              stdin)] = '\0',
                           *_inputPtr++));
    } while ((x) <= ' ');
    _sign = (x) == '-';
    if (_sign)
      (x) = (*_inputPtr ? *_inputPtr++
                        : (_inputBuffer[fread(_inputPtr = _inputBuffer, 1, 4096,
                                              stdin)] = '\0',
                           *_inputPtr++));
    for ((x) -= '0';
         (_c = (*_inputPtr ? *_inputPtr++
                           : (_inputBuffer[fread(_inputPtr = _inputBuffer, 1,
                             4096, stdin)] = '\0',
                                   *_inputPtr++))) >= '0';
         (x) = (x)*10 + _c - '0')
      ;
    if (_sign) (x) = -(x);
  } while (0);
}
void read(double &x) {
  do {
    do {
      (x) = (*_inputPtr ? *_inputPtr++
                        : (_inputBuffer[fread(_inputPtr = _inputBuffer, 1, 4096,
                                              stdin)] = '\0',
                           *_inputPtr++));
    } while ((x) <= ' ');
    _sign = (x) == '-';
    if (_sign)
      (x) = (*_inputPtr ? *_inputPtr++
                        : (_inputBuffer[fread(_inputPtr = _inputBuffer, 1, 4096,
                                              stdin)] = '\0',
                           *_inputPtr++));
    for ((x) -= '0';
         (_c = (*_inputPtr ? *_inputPtr++
                           : (_inputBuffer[fread(_inputPtr = _inputBuffer, 1,
                             4096, stdin)] = '\0',
                                   *_inputPtr++))) >= '0';
         (x) = (x)*10 + _c - '0')
      ;
    if (_c == '.')
      for (double _div = 1.0;
           (_c = (*_inputPtr ? *_inputPtr++
                             : (_inputBuffer[fread(_inputPtr = _inputBuffer, 1,
                               4096, stdin)] = '\0',
                                     *_inputPtr++))) >= '0';
           (x) += (_c - '0') / (_div *= 10))
        ;
    if (_sign) (x) = -(x);
  } while (0);
}
void read(long double &x) {
  do {
    do {
      (x) = (*_inputPtr ? *_inputPtr++
                        : (_inputBuffer[fread(_inputPtr = _inputBuffer, 1, 4096,
                                              stdin)] = '\0',
                           *_inputPtr++));
    } while ((x) <= ' ');
    _sign = (x) == '-';
    if (_sign)
      (x) = (*_inputPtr ? *_inputPtr++
                        : (_inputBuffer[fread(_inputPtr = _inputBuffer, 1, 4096,
                                              stdin)] = '\0',
                           *_inputPtr++));
    for ((x) -= '0';
         (_c = (*_inputPtr ? *_inputPtr++
                           : (_inputBuffer[fread(_inputPtr = _inputBuffer, 1,
                             4096, stdin)] = '\0',
                                   *_inputPtr++))) >= '0';
         (x) = (x)*10 + _c - '0')
      ;
    if (_c == '.')
      for (long double _div = 1.0;
           (_c = (*_inputPtr ? *_inputPtr++
                             : (_inputBuffer[fread(_inputPtr = _inputBuffer, 1,
                               4096, stdin)] = '\0',
                                     *_inputPtr++))) >= '0';
           (x) += (_c - '0') / (_div *= 10))
        ;
    if (_sign) (x) = -(x);
  } while (0);
}
void read(char &x) {
  do {
    do {
      (x) = (*_inputPtr ? *_inputPtr++
                        : (_inputBuffer[fread(_inputPtr = _inputBuffer, 1, 4096,
                                              stdin)] = '\0',
                           *_inputPtr++));
    } while ((x) <= ' ');
  } while (0);
}
void read(char *x) {
  do {
    _cur = 0;
    do {
      _c = (*_inputPtr ? *_inputPtr++
                       : (_inputBuffer[fread(_inputPtr = _inputBuffer, 1, 4096,
                                             stdin)] = '\0',
                          *_inputPtr++));
    } while (_c <= ' ');
    do {
      (x)[_cur++] = _c;
    } while ((_c = (*_inputPtr ? *_inputPtr++
                               : (_inputBuffer[fread(_inputPtr = _inputBuffer,
                                                     1, 4096, stdin)] = '\0',
                                  *_inputPtr++))) > ' ');
    (x)[_cur] = '\0';
  } while (0);
}
void read(string &x) {
  do {
    if (!_tempInputBuf) assert(0);
    do {
      _cur = 0;
      do {
        _c = (*_inputPtr ? *_inputPtr++
                         : (_inputBuffer[fread(_inputPtr = _inputBuffer, 1,
                                               4096, stdin)] = '\0',
                            *_inputPtr++));
      } while (_c <= ' ');
      do {
        (_tempInputBuf)[_cur++] = _c;
      } while ((_c = (*_inputPtr ? *_inputPtr++
                                 : (_inputBuffer[fread(_inputPtr = _inputBuffer,
                                                       1, 4096, stdin)] = '\0',
                                    *_inputPtr++))) > ' ');
      (_tempInputBuf)[_cur] = '\0';
    } while (0);
    (x) = string(_tempInputBuf, _cur);
  } while (0);
}
bool hasNext() {
  while ((*_inputPtr || !feof(stdin)) &&
         (*_inputPtr
              ? *_inputPtr
              : (_inputBuffer[fread(_inputPtr = _inputBuffer, 1, 4096, stdin)] =
                     '\0',
                 *_inputPtr)) <= ' ')
    (*_inputPtr
         ? *_inputPtr++
         : (_inputBuffer[fread(_inputPtr = _inputBuffer, 1, 4096, stdin)] =
                '\0',
            *_inputPtr++));
  return (*_inputPtr || !feof(stdin));
}
template <typename T, typename... Ts>
void read(T &&x, Ts &&...xs) {
  read(x);
  read(forward<Ts>(xs)...);
}
void write(bool x) {
  do {
    if (x)
      (_tempOutputBuf[_tempOutputPtr++] = ('1'));
    else
      (_tempOutputBuf[_tempOutputPtr++] = ('0'));
    int _tempLen = _tempOutputPtr;
    for (int _i = 0; _i < (_width - _tempLen); _i++)
      (_outputBuffer[_outputPtr == 4096
                         ? (fwrite(_outputBuffer, 1, _outputPtr, stdout),
                            _outputPtr = 0)
                         : _outputPtr] = (_fill),
       _outputPtr++);
    for (int _i = 0; _i < _tempOutputPtr;
         (_outputBuffer[_outputPtr == 4096
                            ? (fwrite(_outputBuffer, 1, _outputPtr, stdout),
                               _outputPtr = 0)
                            : _outputPtr] = (_tempOutputBuf[_i++]),
                              _outputPtr++))
      ;
    _tempOutputPtr = 0;
    for (int _i = 0; _i < (-_width - _tempLen); _i++)
      (_outputBuffer[_outputPtr == 4096
                         ? (fwrite(_outputBuffer, 1, _outputPtr, stdout),
                            _outputPtr = 0)
                         : _outputPtr] = (_fill),
       _outputPtr++);
  } while (0);
}
void write(int x) {
  do {
    if ((x) < 0) {
      (_tempOutputBuf[_tempOutputPtr++] = ('-'));
      _cnt = 0;
      for (unsigned int _y = (-(x)); _y; _y /= 10, _cnt++)
        _numBuf[_numPtr++] = '0' + _y % 10;
      for (; _cnt < 1; _cnt++) _numBuf[_numPtr++] = '0';
      for (; _numPtr; (_tempOutputBuf[_tempOutputPtr++] = (_numBuf[--_numPtr])))
        ;
      ;
    } else {
      _cnt = 0;
      for (unsigned int _y = (x); _y; _y /= 10, _cnt++)
        _numBuf[_numPtr++] = '0' + _y % 10;
      for (; _cnt < 1; _cnt++) _numBuf[_numPtr++] = '0';
      for (; _numPtr; (_tempOutputBuf[_tempOutputPtr++] = (_numBuf[--_numPtr])))
        ;
      ;
    }
    int _tempLen = _tempOutputPtr;
    for (int _i = 0; _i < (_width - _tempLen); _i++)
      (_outputBuffer[_outputPtr == 4096
                         ? (fwrite(_outputBuffer, 1, _outputPtr, stdout),
                            _outputPtr = 0)
                         : _outputPtr] = (_fill),
       _outputPtr++);
    for (int _i = 0; _i < _tempOutputPtr;
         (_outputBuffer[_outputPtr == 4096
                            ? (fwrite(_outputBuffer, 1, _outputPtr, stdout),
                               _outputPtr = 0)
                            : _outputPtr] = (_tempOutputBuf[_i++]),
                              _outputPtr++))
      ;
    _tempOutputPtr = 0;
    for (int _i = 0; _i < (-_width - _tempLen); _i++)
      (_outputBuffer[_outputPtr == 4096
                         ? (fwrite(_outputBuffer, 1, _outputPtr, stdout),
                            _outputPtr = 0)
                         : _outputPtr] = (_fill),
       _outputPtr++);
  } while (0);
}
void write(unsigned int x) {
  do {
    if ((x) < 0) {
      (_tempOutputBuf[_tempOutputPtr++] = ('-'));
      _cnt = 0;
      for (unsigned int _y = (-(x)); _y; _y /= 10, _cnt++)
        _numBuf[_numPtr++] = '0' + _y % 10;
      for (; _cnt < 1; _cnt++) _numBuf[_numPtr++] = '0';
      for (; _numPtr; (_tempOutputBuf[_tempOutputPtr++] = (_numBuf[--_numPtr])))
        ;
      ;
    } else {
      _cnt = 0;
      for (unsigned int _y = (x); _y; _y /= 10, _cnt++)
        _numBuf[_numPtr++] = '0' + _y % 10;
      for (; _cnt < 1; _cnt++) _numBuf[_numPtr++] = '0';
      for (; _numPtr; (_tempOutputBuf[_tempOutputPtr++] = (_numBuf[--_numPtr])))
        ;
      ;
    }
    int _tempLen = _tempOutputPtr;
    for (int _i = 0; _i < (_width - _tempLen); _i++)
      (_outputBuffer[_outputPtr == 4096
                         ? (fwrite(_outputBuffer, 1, _outputPtr, stdout),
                            _outputPtr = 0)
                         : _outputPtr] = (_fill),
       _outputPtr++);
    for (int _i = 0; _i < _tempOutputPtr;
         (_outputBuffer[_outputPtr == 4096
                            ? (fwrite(_outputBuffer, 1, _outputPtr, stdout),
                               _outputPtr = 0)
                            : _outputPtr] = (_tempOutputBuf[_i++]),
                              _outputPtr++))
      ;
    _tempOutputPtr = 0;
    for (int _i = 0; _i < (-_width - _tempLen); _i++)
      (_outputBuffer[_outputPtr == 4096
                         ? (fwrite(_outputBuffer, 1, _outputPtr, stdout),
                            _outputPtr = 0)
                         : _outputPtr] = (_fill),
       _outputPtr++);
  } while (0);
}
void write(long long x) {
  do {
    if ((x) < 0) {
      (_tempOutputBuf[_tempOutputPtr++] = ('-'));
      _cnt = 0;
      for (unsigned long long _y = (-(x)); _y; _y /= 10, _cnt++)
        _numBuf[_numPtr++] = '0' + _y % 10;
      for (; _cnt < 1; _cnt++) _numBuf[_numPtr++] = '0';
      for (; _numPtr; (_tempOutputBuf[_tempOutputPtr++] = (_numBuf[--_numPtr])))
        ;
      ;
    } else {
      _cnt = 0;
      for (unsigned long long _y = (x); _y; _y /= 10, _cnt++)
        _numBuf[_numPtr++] = '0' + _y % 10;
      for (; _cnt < 1; _cnt++) _numBuf[_numPtr++] = '0';
      for (; _numPtr; (_tempOutputBuf[_tempOutputPtr++] = (_numBuf[--_numPtr])))
        ;
      ;
    }
    int _tempLen = _tempOutputPtr;
    for (int _i = 0; _i < (_width - _tempLen); _i++)
      (_outputBuffer[_outputPtr == 4096
                         ? (fwrite(_outputBuffer, 1, _outputPtr, stdout),
                            _outputPtr = 0)
                         : _outputPtr] = (_fill),
       _outputPtr++);
    for (int _i = 0; _i < _tempOutputPtr;
         (_outputBuffer[_outputPtr == 4096
                            ? (fwrite(_outputBuffer, 1, _outputPtr, stdout),
                               _outputPtr = 0)
                            : _outputPtr] = (_tempOutputBuf[_i++]),
                              _outputPtr++))
      ;
    _tempOutputPtr = 0;
    for (int _i = 0; _i < (-_width - _tempLen); _i++)
      (_outputBuffer[_outputPtr == 4096
                         ? (fwrite(_outputBuffer, 1, _outputPtr, stdout),
                            _outputPtr = 0)
                         : _outputPtr] = (_fill),
       _outputPtr++);
  } while (0);
}
void write(unsigned long long x) {
  do {
    if ((x) < 0) {
      (_tempOutputBuf[_tempOutputPtr++] = ('-'));
      _cnt = 0;
      for (unsigned long long _y = (-(x)); _y; _y /= 10, _cnt++)
        _numBuf[_numPtr++] = '0' + _y % 10;
      for (; _cnt < 1; _cnt++) _numBuf[_numPtr++] = '0';
      for (; _numPtr; (_tempOutputBuf[_tempOutputPtr++] = (_numBuf[--_numPtr])))
        ;
      ;
    } else {
      _cnt = 0;
      for (unsigned long long _y = (x); _y; _y /= 10, _cnt++)
        _numBuf[_numPtr++] = '0' + _y % 10;
      for (; _cnt < 1; _cnt++) _numBuf[_numPtr++] = '0';
      for (; _numPtr; (_tempOutputBuf[_tempOutputPtr++] = (_numBuf[--_numPtr])))
        ;
      ;
    }
    int _tempLen = _tempOutputPtr;
    for (int _i = 0; _i < (_width - _tempLen); _i++)
      (_outputBuffer[_outputPtr == 4096
                         ? (fwrite(_outputBuffer, 1, _outputPtr, stdout),
                            _outputPtr = 0)
                         : _outputPtr] = (_fill),
       _outputPtr++);
    for (int _i = 0; _i < _tempOutputPtr;
         (_outputBuffer[_outputPtr == 4096
                            ? (fwrite(_outputBuffer, 1, _outputPtr, stdout),
                               _outputPtr = 0)
                            : _outputPtr] = (_tempOutputBuf[_i++]),
                              _outputPtr++))
      ;
    _tempOutputPtr = 0;
    for (int _i = 0; _i < (-_width - _tempLen); _i++)
      (_outputBuffer[_outputPtr == 4096
                         ? (fwrite(_outputBuffer, 1, _outputPtr, stdout),
                            _outputPtr = 0)
                         : _outputPtr] = (_fill),
       _outputPtr++);
  } while (0);
}
void write(double x) {
  do {
    if (std::isnan(x)) {
      do {
        int _slen = strlen("NaN");
        for (int _i = 0; _i < (_width - _slen); _i++)
          (_outputBuffer[_outputPtr == 4096
                             ? (fwrite(_outputBuffer, 1, _outputPtr, stdout),
                                _outputPtr = 0)
                             : _outputPtr] = (_fill),
           _outputPtr++);
        for (const char *_p = ("NaN"); *_p;
             (_outputBuffer[_outputPtr == 4096
                                ? (fwrite(_outputBuffer, 1, _outputPtr, stdout),
                                   _outputPtr = 0)
                                : _outputPtr] = (*_p++),
                                  _outputPtr++))
          ;
        for (int _i = 0; _i < (-_width - _slen); _i++)
          (_outputBuffer[_outputPtr == 4096
                             ? (fwrite(_outputBuffer, 1, _outputPtr, stdout),
                                _outputPtr = 0)
                             : _outputPtr] = (_fill),
           _outputPtr++);
      } while (0);
    } else if (std::isinf(x)) {
      do {
        int _slen = strlen("Inf");
        for (int _i = 0; _i < (_width - _slen); _i++)
          (_outputBuffer[_outputPtr == 4096
                             ? (fwrite(_outputBuffer, 1, _outputPtr, stdout),
                                _outputPtr = 0)
                             : _outputPtr] = (_fill),
           _outputPtr++);
        for (const char *_p = ("Inf"); *_p;
             (_outputBuffer[_outputPtr == 4096
                                ? (fwrite(_outputBuffer, 1, _outputPtr, stdout),
                                   _outputPtr = 0)
                                : _outputPtr] = (*_p++),
                                  _outputPtr++))
          ;
        for (int _i = 0; _i < (-_width - _slen); _i++)
          (_outputBuffer[_outputPtr == 4096
                             ? (fwrite(_outputBuffer, 1, _outputPtr, stdout),
                                _outputPtr = 0)
                             : _outputPtr] = (_fill),
           _outputPtr++);
      } while (0);
    } else if ((x) < 0) {
      (_tempOutputBuf[_tempOutputPtr++] = ('-'));
      unsigned long long _I = (unsigned long long)(-(x));
      unsigned long long _F = ((-(x)) - _I) * _precisionBase + (double)(0.5);
      if (_F >= _precisionBase) {
        _I++;
        _F = 0;
      }
      _cnt = 0;
      for (unsigned long long _y = (_I); _y; _y /= 10, _cnt++)
        _numBuf[_numPtr++] = '0' + _y % 10;
      for (; _cnt < 1; _cnt++) _numBuf[_numPtr++] = '0';
      for (; _numPtr; (_tempOutputBuf[_tempOutputPtr++] = (_numBuf[--_numPtr])))
        ;
      ;
      (_tempOutputBuf[_tempOutputPtr++] = ('.'));
      _cnt = 0;
      for (unsigned long long _y = (_F); _y; _y /= 10, _cnt++)
        _numBuf[_numPtr++] = '0' + _y % 10;
      for (; _cnt < _precision; _cnt++) _numBuf[_numPtr++] = '0';
      for (; _numPtr; (_tempOutputBuf[_tempOutputPtr++] = (_numBuf[--_numPtr])))
        ;
      ;
    } else {
      unsigned long long _I = (unsigned long long)(x);
      unsigned long long _F = ((x)-_I) * _precisionBase + (double)(0.5);
      if (_F >= _precisionBase) {
        _I++;
        _F = 0;
      }
      _cnt = 0;
      for (unsigned long long _y = (_I); _y; _y /= 10, _cnt++)
        _numBuf[_numPtr++] = '0' + _y % 10;
      for (; _cnt < 1; _cnt++) _numBuf[_numPtr++] = '0';
      for (; _numPtr; (_tempOutputBuf[_tempOutputPtr++] = (_numBuf[--_numPtr])))
        ;
      ;
      (_tempOutputBuf[_tempOutputPtr++] = ('.'));
      _cnt = 0;
      for (unsigned long long _y = (_F); _y; _y /= 10, _cnt++)
        _numBuf[_numPtr++] = '0' + _y % 10;
      for (; _cnt < _precision; _cnt++) _numBuf[_numPtr++] = '0';
      for (; _numPtr; (_tempOutputBuf[_tempOutputPtr++] = (_numBuf[--_numPtr])))
        ;
      ;
    }
    int _tempLen = _tempOutputPtr;
    for (int _i = 0; _i < (_width - _tempLen); _i++)
      (_outputBuffer[_outputPtr == 4096
                         ? (fwrite(_outputBuffer, 1, _outputPtr, stdout),
                            _outputPtr = 0)
                         : _outputPtr] = (_fill),
       _outputPtr++);
    for (int _i = 0; _i < _tempOutputPtr;
         (_outputBuffer[_outputPtr == 4096
                            ? (fwrite(_outputBuffer, 1, _outputPtr, stdout),
                               _outputPtr = 0)
                            : _outputPtr] = (_tempOutputBuf[_i++]),
                              _outputPtr++))
      ;
    _tempOutputPtr = 0;
    for (int _i = 0; _i < (-_width - _tempLen); _i++)
      (_outputBuffer[_outputPtr == 4096
                         ? (fwrite(_outputBuffer, 1, _outputPtr, stdout),
                            _outputPtr = 0)
                         : _outputPtr] = (_fill),
       _outputPtr++);
  } while (0);
}
void write(long double x) {
  do {
    if (std::isnan(x)) {
      do {
        int _slen = strlen("NaN");
        for (int _i = 0; _i < (_width - _slen); _i++)
          (_outputBuffer[_outputPtr == 4096
                             ? (fwrite(_outputBuffer, 1, _outputPtr, stdout),
                                _outputPtr = 0)
                             : _outputPtr] = (_fill),
           _outputPtr++);
        for (const char *_p = ("NaN"); *_p;
             (_outputBuffer[_outputPtr == 4096
                                ? (fwrite(_outputBuffer, 1, _outputPtr, stdout),
                                   _outputPtr = 0)
                                : _outputPtr] = (*_p++),
                                  _outputPtr++))
          ;
        for (int _i = 0; _i < (-_width - _slen); _i++)
          (_outputBuffer[_outputPtr == 4096
                             ? (fwrite(_outputBuffer, 1, _outputPtr, stdout),
                                _outputPtr = 0)
                             : _outputPtr] = (_fill),
           _outputPtr++);
      } while (0);
    } else if (std::isinf(x)) {
      do {
        int _slen = strlen("Inf");
        for (int _i = 0; _i < (_width - _slen); _i++)
          (_outputBuffer[_outputPtr == 4096
                             ? (fwrite(_outputBuffer, 1, _outputPtr, stdout),
                                _outputPtr = 0)
                             : _outputPtr] = (_fill),
           _outputPtr++);
        for (const char *_p = ("Inf"); *_p;
             (_outputBuffer[_outputPtr == 4096
                                ? (fwrite(_outputBuffer, 1, _outputPtr, stdout),
                                   _outputPtr = 0)
                                : _outputPtr] = (*_p++),
                                  _outputPtr++))
          ;
        for (int _i = 0; _i < (-_width - _slen); _i++)
          (_outputBuffer[_outputPtr == 4096
                             ? (fwrite(_outputBuffer, 1, _outputPtr, stdout),
                                _outputPtr = 0)
                             : _outputPtr] = (_fill),
           _outputPtr++);
      } while (0);
    } else if ((x) < 0) {
      (_tempOutputBuf[_tempOutputPtr++] = ('-'));
      unsigned long long _I = (unsigned long long)(-(x));
      unsigned long long _F =
          ((-(x)) - _I) * _precisionBase + (long double)(0.5);
      if (_F >= _precisionBase) {
        _I++;
        _F = 0;
      }
      _cnt = 0;
      for (unsigned long long _y = (_I); _y; _y /= 10, _cnt++)
        _numBuf[_numPtr++] = '0' + _y % 10;
      for (; _cnt < 1; _cnt++) _numBuf[_numPtr++] = '0';
      for (; _numPtr; (_tempOutputBuf[_tempOutputPtr++] = (_numBuf[--_numPtr])))
        ;
      ;
      (_tempOutputBuf[_tempOutputPtr++] = ('.'));
      _cnt = 0;
      for (unsigned long long _y = (_F); _y; _y /= 10, _cnt++)
        _numBuf[_numPtr++] = '0' + _y % 10;
      for (; _cnt < _precision; _cnt++) _numBuf[_numPtr++] = '0';
      for (; _numPtr; (_tempOutputBuf[_tempOutputPtr++] = (_numBuf[--_numPtr])))
        ;
      ;
    } else {
      unsigned long long _I = (unsigned long long)(x);
      unsigned long long _F = ((x)-_I) * _precisionBase + (long double)(0.5);
      if (_F >= _precisionBase) {
        _I++;
        _F = 0;
      }
      _cnt = 0;
      for (unsigned long long _y = (_I); _y; _y /= 10, _cnt++)
        _numBuf[_numPtr++] = '0' + _y % 10;
      for (; _cnt < 1; _cnt++) _numBuf[_numPtr++] = '0';
      for (; _numPtr; (_tempOutputBuf[_tempOutputPtr++] = (_numBuf[--_numPtr])))
        ;
      ;
      (_tempOutputBuf[_tempOutputPtr++] = ('.'));
      _cnt = 0;
      for (unsigned long long _y = (_F); _y; _y /= 10, _cnt++)
        _numBuf[_numPtr++] = '0' + _y % 10;
      for (; _cnt < _precision; _cnt++) _numBuf[_numPtr++] = '0';
      for (; _numPtr; (_tempOutputBuf[_tempOutputPtr++] = (_numBuf[--_numPtr])))
        ;
      ;
    }
    int _tempLen = _tempOutputPtr;
    for (int _i = 0; _i < (_width - _tempLen); _i++)
      (_outputBuffer[_outputPtr == 4096
                         ? (fwrite(_outputBuffer, 1, _outputPtr, stdout),
                            _outputPtr = 0)
                         : _outputPtr] = (_fill),
       _outputPtr++);
    for (int _i = 0; _i < _tempOutputPtr;
         (_outputBuffer[_outputPtr == 4096
                            ? (fwrite(_outputBuffer, 1, _outputPtr, stdout),
                               _outputPtr = 0)
                            : _outputPtr] = (_tempOutputBuf[_i++]),
                              _outputPtr++))
      ;
    _tempOutputPtr = 0;
    for (int _i = 0; _i < (-_width - _tempLen); _i++)
      (_outputBuffer[_outputPtr == 4096
                         ? (fwrite(_outputBuffer, 1, _outputPtr, stdout),
                            _outputPtr = 0)
                         : _outputPtr] = (_fill),
       _outputPtr++);
  } while (0);
}
void write(char x) {
  do {
    (_tempOutputBuf[_tempOutputPtr++] = (x));
    int _tempLen = _tempOutputPtr;
    for (int _i = 0; _i < (_width - _tempLen); _i++)
      (_outputBuffer[_outputPtr == 4096
                         ? (fwrite(_outputBuffer, 1, _outputPtr, stdout),
                            _outputPtr = 0)
                         : _outputPtr] = (_fill),
       _outputPtr++);
    for (int _i = 0; _i < _tempOutputPtr;
         (_outputBuffer[_outputPtr == 4096
                            ? (fwrite(_outputBuffer, 1, _outputPtr, stdout),
                               _outputPtr = 0)
                            : _outputPtr] = (_tempOutputBuf[_i++]),
                              _outputPtr++))
      ;
    _tempOutputPtr = 0;
    for (int _i = 0; _i < (-_width - _tempLen); _i++)
      (_outputBuffer[_outputPtr == 4096
                         ? (fwrite(_outputBuffer, 1, _outputPtr, stdout),
                            _outputPtr = 0)
                         : _outputPtr] = (_fill),
       _outputPtr++);
  } while (0);
}
void write(char *x) {
  do {
    int _slen = strlen(x);
    for (int _i = 0; _i < (_width - _slen); _i++)
      (_outputBuffer[_outputPtr == 4096
                         ? (fwrite(_outputBuffer, 1, _outputPtr, stdout),
                            _outputPtr = 0)
                         : _outputPtr] = (_fill),
       _outputPtr++);
    for (const char *_p = (x); *_p;
         (_outputBuffer[_outputPtr == 4096
                            ? (fwrite(_outputBuffer, 1, _outputPtr, stdout),
                               _outputPtr = 0)
                            : _outputPtr] = (*_p++),
                              _outputPtr++))
      ;
    for (int _i = 0; _i < (-_width - _slen); _i++)
      (_outputBuffer[_outputPtr == 4096
                         ? (fwrite(_outputBuffer, 1, _outputPtr, stdout),
                            _outputPtr = 0)
                         : _outputPtr] = (_fill),
       _outputPtr++);
  } while (0);
}
void write(const char *x) {
  do {
    int _slen = strlen(x);
    for (int _i = 0; _i < (_width - _slen); _i++)
      (_outputBuffer[_outputPtr == 4096
                         ? (fwrite(_outputBuffer, 1, _outputPtr, stdout),
                            _outputPtr = 0)
                         : _outputPtr] = (_fill),
       _outputPtr++);
    for (const char *_p = (x); *_p;
         (_outputBuffer[_outputPtr == 4096
                            ? (fwrite(_outputBuffer, 1, _outputPtr, stdout),
                               _outputPtr = 0)
                            : _outputPtr] = (*_p++),
                              _outputPtr++))
      ;
    for (int _i = 0; _i < (-_width - _slen); _i++)
      (_outputBuffer[_outputPtr == 4096
                         ? (fwrite(_outputBuffer, 1, _outputPtr, stdout),
                            _outputPtr = 0)
                         : _outputPtr] = (_fill),
       _outputPtr++);
  } while (0);
}
void write(string &x) {
  do {
    for (int _i = 0; _i < (_width - (int)(x).length()); _i++)
      (_outputBuffer[_outputPtr == 4096
                         ? (fwrite(_outputBuffer, 1, _outputPtr, stdout),
                            _outputPtr = 0)
                         : _outputPtr] = (_fill),
       _outputPtr++);
    for (int _i = 0; _i < (int)(x).length();
         (_outputBuffer[_outputPtr == 4096
                            ? (fwrite(_outputBuffer, 1, _outputPtr, stdout),
                               _outputPtr = 0)
                            : _outputPtr] = (x[_i++]),
                              _outputPtr++))
      ;
    for (int _i = 0; _i < (-_width - (int)(x).length()); _i++)
      (_outputBuffer[_outputPtr == 4096
                         ? (fwrite(_outputBuffer, 1, _outputPtr, stdout),
                            _outputPtr = 0)
                         : _outputPtr] = (_fill),
       _outputPtr++);
  } while (0);
}
template <typename T, typename... Ts>
void write(T &&x, Ts &&...xs) {
  write(x);
  for (const char *_p = _delimiter; *_p;
       (_outputBuffer[_outputPtr == 4096
                          ? (fwrite(_outputBuffer, 1, _outputPtr, stdout),
                             _outputPtr = 0)
                          : _outputPtr] = (*_p++),
                            _outputPtr++))
    ;
  write(forward<Ts>(xs)...);
}
void writeln() {
  (_outputBuffer[_outputPtr == 4096
                     ? (fwrite(_outputBuffer, 1, _outputPtr, stdout),
                        _outputPtr = 0)
                     : _outputPtr] = ('\n'),
   _outputPtr++);
}
template <typename... Ts>
void writeln(Ts &&...xs) {
  write(forward<Ts>(xs)...);
  (_outputBuffer[_outputPtr == 4096
                     ? (fwrite(_outputBuffer, 1, _outputPtr, stdout),
                        _outputPtr = 0)
                     : _outputPtr] = ('\n'),
   _outputPtr++);
}
void flush() {
  do {
    (fwrite(_outputBuffer, 1, _outputPtr, stdout), _outputPtr = 0);
    fflush(stdout);
  } while (0);
}
class IOManager {
 public:
  ~IOManager() { flush(); }
};
unique_ptr<IOManager> iomanager;
const double EPS = 1e-9;
struct Vector {
 private:
  int d;
  vector<double> data;

 public:
  Vector() {}
  Vector(int d) : d(d), data(d, 0.0) {}
  Vector(int d, double *a) : d(d), data(a, a + d) {}
  Vector(const vector<int> &v) : d(v.size()), data(v.begin(), v.end()) {}
  int dimension() const { return d; }
  double dot(const Vector &that) const {
    if (d != that.d) throw invalid_argument("Dimensions don't agree");
    double sum = 0.0;
    for (int i = 0; i < d; i++) sum = sum + (data[i] * that.data[i]);
    return sum;
  }
  double operator*(const Vector &that) const { return dot(that); }
  double cross2D(const Vector &that) const {
    if (d != 2 || that.d != 2)
      throw invalid_argument("Vectors must be 2-dimensional");
    return data[0] * that.data[1] - data[1] * that.data[0];
  }
  double operator|(const Vector &that) const { return cross2D(that); }
  Vector cross3D(const Vector &that) const {
    if (d != 3 || that.d != 3)
      throw invalid_argument("Vectors must be 3-dimensional");
    Vector c(d);
    c.data[0] = data[1] * that.data[2] - data[2] * that.data[1];
    c.data[1] = data[2] * that.data[0] - data[0] * that.data[2];
    c.data[2] = data[0] * that.data[1] - data[1] * that.data[0];
    return c;
  }
  Vector operator^(const Vector &that) const { return cross3D(that); }
  double magnitude() const { return sqrt(this->dot(*this)); }
  double distanceTo(const Vector &that) const {
    if (d != that.d) throw invalid_argument("Dimensions don't agree");
    return minus(that).magnitude();
  }
  Vector plus(const Vector &that) const {
    if (d != that.d) throw invalid_argument("Dimensions don't agree");
    Vector c(d);
    for (int i = 0; i < d; i++) c.data[i] = data[i] + that.data[i];
    return c;
  }
  Vector operator+(const Vector &that) const { return plus(that); }
  Vector minus(const Vector &that) const {
    if (d != that.d) throw invalid_argument("Dimensions don't agree");
    Vector c(d);
    for (int i = 0; i < d; i++) c.data[i] = data[i] - that.data[i];
    return c;
  }
  Vector operator-(const Vector &that) const { return minus(that); }
  double cartesian(int i) const { return data[i]; }
  double &operator[](int i) { return data[i]; }
  double operator[](int i) const { return data[i]; }
  Vector scale(double alpha) const {
    Vector c(d);
    for (int i = 0; i < d; i++) c.data[i] = alpha * data[i];
    return c;
  }
  Vector operator*(double alpha) const { return scale(alpha); }
  Vector operator/(double alpha) const { return scale(1.0 / alpha); }
  Vector direction() const {
    if (magnitude() <= EPS) throw runtime_error("Zero-vector has no direction");
    return scale(1.0 / magnitude());
  }
  double directionCosine(int i) const { return data[i] / magnitude(); }
  Vector projectionOn(const Vector &that) const {
    if (d != that.d) throw invalid_argument("Dimensions don't agree");
    return that.scale(dot(that) / that.dot(that));
  }
  Vector rotate(Vector &that, double theta) const {
    if (d == 2 && that.d == 2) {
      Vector r(2);
      r.data[0] = that.data[0] + (data[0] - that.data[0]) * cos(theta) -
                  (data[1] - that.data[1]) * sin(theta);
      r.data[1] = that.data[1] + (data[0] - that.data[0]) * sin(theta) +
                  (data[1] - that.data[1]) * cos(theta);
      return r;
    } else if (d == 3 && that.d == 3) {
      return scale(cos(theta))
          .plus(that.direction().cross3D(*this).scale(sin(theta)))
          .plus(that.direction()
                    .scale(that.direction().dot(*this))
                    .scale(1.0 - cos(theta)));
    } else if (d == that.d) {
      throw invalid_argument("Vectors must be 2-dimensional or 3-dimensional");
    } else {
      throw invalid_argument("Dimensions don't agree");
    }
  }
  bool operator<(const Vector &that) const {
    for (int i = 0; i < d; i++)
      if (abs(data[i] - that.data[i]) > EPS) return data[i] < that.data[i];
    return false;
  }
};
Vector intersection(const pair<Vector, Vector> &a,
                    const pair<Vector, Vector> &b) {
  Vector c = (b.first - a.first) ^ b.second;
  Vector d = (a.second ^ b.second);
  double alpha = (c.magnitude() * (c < Vector(3) ? -1 : 1)) /
                 (d.magnitude() * (d < Vector(3) ? -1 : 1));
  return a.first + a.second * alpha;
}
void solve(const vector<Vector> &A, const vector<Vector> &B,
           vector<pair<Vector, pair<int, int>>> &events, int id) {
  pair<Vector, Vector> H1 = {A[0], ((A[0] - A[1]) ^ (A[2] - A[0])).direction()},
                       H2 = {B[0], ((B[0] - B[1]) ^ (B[2] - B[0])).direction()};
  Vector cross = H1.second ^ H2.second;
  if (cross.magnitude() <= EPS) return;
  Vector cross2 = (cross ^ H1.second).direction();
  cross = cross.direction();
  pair<Vector, Vector> line = {
      H1.first +
          cross2 * (((H2.first - H1.first) * H2.second) / (cross2 * H2.second)),
      cross};
  vector<pair<Vector, pair<int, int>>> v;
  for (auto i = (0); i < (((int)(A).size())); i++) {
    Vector a = A[i], b = A[(i + 1) % ((int)(A).size())];
    double dota = (a - line.first) * cross2, dotb = (b - line.first) * cross2;
    int signa = dota > EPS ? 1 : (dota < -EPS ? -1 : 0),
        signb = dotb > EPS ? 1 : (dotb < -EPS ? -1 : 0);
    if (signa != signb) {
      Vector POI = intersection({a, b - a}, line);
      if (signa != 0 && signb != 0)
        events.push_back({POI, {signa, id}});
      else
        v.push_back({POI, {signa, signb}});
    }
  }
  for (auto i = (0); i < (((int)(v).size())); i++)
    if (v[i].second.second == 0)
      if (v[i].second.first != v[(i + 1) % ((int)(v).size())].second.second)
        events.push_back({v[i].first, {v[i].second.first, id}});
}
int main() {
  iomanager.reset(new IOManager());
  int N, M;
  vector<Vector> A, B;
  read(N);
  for (auto i = (0); i < (N); i++) {
    A.push_back(Vector(3));
    for (auto j = (0); j < (3); j++) read(A[i][j]);
  }
  read(M);
  for (auto i = (0); i < (M); i++) {
    B.push_back(Vector(3));
    for (auto j = (0); j < (3); j++) read(B[i][j]);
  }
  vector<pair<Vector, pair<int, int>>> events;
  solve(A, B, events, 0);
  solve(B, A, events, 1);
  int ans = 0, cur = 0;
  sort((events).begin(), (events).end());
  for (pair<Vector, pair<int, int>> &e : events) {
    if (e.second.second == 1)
      cur += e.second.first;
    else if (cur != 0)
      ans += e.second.first;
  }
  writeln(ans == 0 ? "NO" : "YES");
  return 0;
}
