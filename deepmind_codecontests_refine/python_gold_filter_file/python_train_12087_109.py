n=int(input())
x = list(map(int, input().split()))
y=0
for i in range (n):
    y=x[i]+y
if y==0 :
    print("EASY")
else:
    print("HARD")
    