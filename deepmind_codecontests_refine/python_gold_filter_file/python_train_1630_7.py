from math import ceil
k,d,t = map(int, input().split())
up = ceil(k/d)*d
diff = up-k
cook = diff/(2*t) + k/t
tmp = int(1/cook)
left = 1 - cook*tmp
ans = tmp*up
if left <= k/t:
	print(ans+(left/(1/t)) )
else:
	left = left - k/t
	print(ans+k + (left/(1/(2*t))) )

    