A, B, K = map(int, input().split())
AB = range(A, B+1)
 
for i in sorted(set(AB[:K]) | set(AB[-K:])):
    print(i)