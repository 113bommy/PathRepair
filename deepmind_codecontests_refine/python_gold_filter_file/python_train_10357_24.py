N = int(input())
d = {0: "zero", 1: "one", 2: "two", 3: "three", 4: "four", 5: "five", 6: "six", 7: "seven", 8: "eight", 9: "nine"}
dd = {11: "eleven", 12: "twelve", 13: "thirteen", 14: "fourteen", 15: "fifteen", 16: "sixteen", 17: "seventeen", 18: "eighteen", 19: "nineteen"}
ddd = {10: "ten", 20: "twenty", 30: "thirty", 40: "forty", 50: "fifty", 60: "sixty", 70: "seventy", 80: "eighty", 90: "ninety"}

if N <= 9:
    print(d[N])
elif N % 10 == 0:
    print(ddd[N])
elif N <= 19:
    print(dd[N])
else:
    m = N % 10
    n = N - m
    print("{}-{}".format(ddd[n], d[m]))
