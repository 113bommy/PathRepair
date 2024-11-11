a = int(input())
n = list(map(int,input().split()))[1:]
m = list(map(int,input().split()))[1:]
l = n + m
s = set(l)

s.remove(0) if 0 in s else s


if a==len(s):
    print("I become the guy.")
else:
    print("Oh, my keyboard!")