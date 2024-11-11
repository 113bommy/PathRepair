N,A,B = map(int,input().split())

maxi=(N-1)*B + A
mini=(N-1)*A + B

ans = maxi - mini +1

print(max(ans,0))