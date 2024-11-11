# cook your dish here
# cook your dish here
n=int(input())
a1,a2,a3=list(map(int,input().rstrip().split()))
b1,b2,b3=list(map(int,input().rstrip().split()))
max_win = min(a1,b2)+min(a2,b3)+min(a3,b1)
min_win=max(0,b1-(a1+a2),b2-(a2+a3),b3-(a1+a3))
#if (a1==a2 and a2==a3) and(b1==b2 and b2==b3):
#    min_win=0
print(min_win,end=' ')
print(max_win)