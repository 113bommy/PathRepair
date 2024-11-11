# -*- coding: utf-8 -*-

import sys

word = sys.stdin.read().lower()
for i in range(ord('a'), ord('z') + 1):
    print('{0} : {1}'.format(chr(i), word.count(chr(i))))

