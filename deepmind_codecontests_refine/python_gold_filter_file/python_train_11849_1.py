n = int(input())
s = input()

dic = {}
for s_i in set(s):
	dic[s_i] = s.count(s_i)+1

p = 10**9+7
res = 1
for v in dic.values():
	res = (res*v)%p

print(res-1)