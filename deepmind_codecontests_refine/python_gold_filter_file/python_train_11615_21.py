# import sys
# input = lambda : sys.stdin.readline()

c = input()
h , m = map(int, input().split(':'))

if m >= 60:
    m %= 10
if c == "12" and h == 0:
    h = 1
elif c == "12" and h > 12:
    if h%10:
        h %= 10
    else:
        h = 10
elif c == "24" and h > 23:
    h %= 10

print('%02d:%02d'%(h,m))
