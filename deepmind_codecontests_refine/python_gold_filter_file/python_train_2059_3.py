a,v = map(int,input().split())
b,w = map(int,input().split())
t=int(input())
if abs(a-b)>(v-w)*t:
    print("NO")
else:
    print("YES")