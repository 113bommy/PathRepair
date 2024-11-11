import sys
input=sys.stdin.readline

inputs=lambda converter: map(converter,input().split())

def main():
    testc=int(input())
    while testc>0:
        testc-=1
        n,m=list(inputs(int))
        arr=list(inputs(int))
        psum=[0 for i in range(n+1)]
        
        for i in range(n):
            psum[i+1]=psum[i]+arr[i]/(i+1)

        ans=0
        for i in range(n):
            ans+=(psum[n]-psum[i])
        
        if m+0.15>=ans and ans+0.15>=m:
            print("YES")
        else :
            print("NO") 

main()