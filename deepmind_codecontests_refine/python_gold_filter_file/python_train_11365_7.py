ii = lambda: int(input())
mi = lambda: map(int, input().split())
li = lambda: list(mi())

l = ii()
n = input()

ans = int(n)
mid = (l - 1) // 2
for i in range(mid, -1, -1):
	if(n[i + 1] == '0'):
		continue
	ans = min(ans, int(n[0 : i + 1]) + int(n[i + 1 :]))
	break

mid = l // 2
for i in range(mid, l, 1):
	if(n[i] == '0'):
		continue
	ans = min(ans, int(n[0 : i]) + int(n[i : ]))
	break

print(ans)