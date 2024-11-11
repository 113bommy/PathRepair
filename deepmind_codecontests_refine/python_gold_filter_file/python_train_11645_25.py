N,A,B = map(int,input().split())
print(max((N-1)*B+A-(N-1)*A-B+1,0))