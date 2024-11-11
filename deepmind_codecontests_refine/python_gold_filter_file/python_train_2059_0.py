a,v=map(int, input().split())
b,w=map(int, input().split())
t=int(input())
dist=abs(b-a)
dist2=(v-w)*t
if dist>dist2:
	print("NO")
else:
	print("YES")