import sys
l = ""
for i in sys.stdin.readlines():
    l += i.lower().rstrip()
word = "abcdefghijklmnopqrstuvwxyz"
for i in word:
    n = l.count(i)
    print("{} : {}".format(i,n))
