A, B, N = map(int,input().split())

max = int(A*min(B-1,N)/B)
print(max)           