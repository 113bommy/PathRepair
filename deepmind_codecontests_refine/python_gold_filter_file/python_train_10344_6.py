n = int(input())
arr = list(map(int, input().split()))
d = {ele:idx for idx, ele in enumerate(arr)}
m = int(input())
queries = list(map(int, input().split()))
v,p = 0,0
for i in queries:
	temp = d[i]
	v += temp + 1
	p += n-temp
print(v,p)