#!/usr/bin/env python
# -*- coding: utf-8 -*-

n = int(input().strip())
ones = [None, "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"]
tens = [None, "ten", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"]
spec = [None, "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"]

if n == 0:
    print("zero")
elif n < 10:
    print(ones[n])
elif n % 10 == 0:
    print(tens[n // 10])
elif 10 < n < 20:
    print(spec[n-10])
else:
    print(tens[n // 10] + "-" + ones[n % 10])
