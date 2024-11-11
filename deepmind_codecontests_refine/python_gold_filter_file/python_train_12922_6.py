n = int(input())
s = sorted(list([int(i) for i in input().split(' ')]))
if len(s) < 3:print(0)
else:print(min(s[-1] - s[1],s[-2] - s[0]))