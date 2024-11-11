import collections


s = input()
t = input()
s = collections.Counter(s)
t = collections.Counter(t)

if sorted(s.values()) == sorted(t.values()):
    print("Yes")
else:
    print("No")