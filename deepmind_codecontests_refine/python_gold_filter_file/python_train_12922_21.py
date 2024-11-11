n = int(input())
s = [int(i) for i in input().split()]
s1 = s[:]
s2 = s[:]
s1.remove(max(s1))
s2.remove(min(s2))
dif_s1 = max(s1) - min(s1)
dif_s2 = max(s2) - min(s2)
if dif_s1 > dif_s2:
	print(dif_s2)
else:
	print(dif_s1)
