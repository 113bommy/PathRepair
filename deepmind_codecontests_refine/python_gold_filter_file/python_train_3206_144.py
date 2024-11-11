A,B,K = map(int,input().split())

if K <= A:
    print(A-K, B)
else:
    print(0, max(0,A+B-K))