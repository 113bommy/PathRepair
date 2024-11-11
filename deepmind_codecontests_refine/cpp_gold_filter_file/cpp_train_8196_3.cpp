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
unique_ptr<IOManager> _iomanager;
template <typename It, typename Comparator>
int count_inversions(It src_st, It src_en, It dst_st, It dst_en,
                     Comparator cmp) {
  int n = src_en - src_st;
  if (n <= 1) return 0;
  int mid = (n - 1) / 2;
  int ret = 0;
  ret +=
      count_inversions(dst_st, dst_st + mid + 1, src_st, src_st + mid + 1, cmp);
  ret +=
      count_inversions(dst_st + mid + 1, dst_en, src_st + mid + 1, src_en, cmp);
  int i = 0, j = mid + 1;
  for (int k = 0; k < n; k++) {
    if (i > mid) {
      dst_st[k] = src_st[j++];
    } else if (j >= n) {
      dst_st[k] = src_st[i++];
      ret += j - (mid + 1);
    } else if (cmp(src_st[j], src_st[i])) {
      dst_st[k] = src_st[j++];
      ret += mid + 1 - i;
    } else {
      dst_st[k] = src_st[i++];
      ret += j - (mid + 1);
    }
  }
  return ret;
}
template <typename It, typename Comparator>
int count_inversions(It st, It en, Comparator cmp) {
  int n = en - st;
  typename std::iterator_traits<It>::value_type *aux =
      new typename std::iterator_traits<It>::value_type[n];
  for (int i = 0; i < n; i++) aux[i] = st[i];
  int ret = count_inversions(aux, aux + n, st, en, cmp);
  delete[](aux);
  return ret / 2;
}
int N, A[105 * 2], B[105 * 2], firstInd[105], lastInd[105];
bool cmpFirst(int i, int j) { return firstInd[i] < firstInd[j]; }
bool cmpLast(int i, int j) { return lastInd[i] < lastInd[j]; }
int main() {
  _iomanager.reset(new IOManager());
  read(N);
  for (auto i = (0); i < (N); i++) {
    firstInd[i] = 2 * N;
    lastInd[i] = -1;
  }
  for (auto i = (0); i < (2 * N); i++) {
    read(A[i]);
    A[i]--;
    B[i] = A[i];
    ((firstInd[A[i]]) = min((firstInd[A[i]]), (i)));
    ((lastInd[A[i]]) = max((lastInd[A[i]]), (i)));
  }
  writeln(min(count_inversions(A, A + (2 * N), cmpFirst),
              count_inversions(B, B + (2 * N), cmpLast)));
  return 0;
}
