import sys

s = ""
for line in sys.stdin:
    s+=line
s=s.lower()
for str in list("abcdefghijklmnopqrstuvwxyz"):
    print(*[str,":",s.count(str)])
