import sys
input=sys.stdin.readline
memo={}
def prob(w,b):
    if w==0 or b<0:
        return 0
    if b==0:
        return 1
    if (w,b) in memo:
        return  memo[(w,b)]
    ans1=w/(w+b)
    if b==1:
        ans2=0
    else:
        ans2=( b/(w+b) )*( (b-1)/(w+b-1) )*( prob(w-1,b-2)*(w/(b+w-2)) + prob(w,b-3)*((b-2)/(b+w-2)) )
    memo[(w,b)]=ans1+ans2
    return ans1+ans2
w,b=map(int,input().split())
print(prob(w,b))