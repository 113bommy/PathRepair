import sys
input=sys.stdin.readline

def main():
    n,k=map(int,input().split())
    A=list(map(int,input().split()))
    if min(A) == max(A) == k:
        print('yes')
        return
    if k not in A:
        print('no')
        return
    A = [x >= k for x in A] + [0, 0]
    print('yes' if max(sum(A[i:i+3]) for i in range(n)) > 1 else 'no')
 

T=int(input())
for _ in range(T):
       main()
    