A,B,K = map(int,input().split())

for i in range(A,B+1,1):
    if i-A < K or B-i < K:
        print(i)