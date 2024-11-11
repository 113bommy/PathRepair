def solve(M, N): 
    tileArea = 2*1 
    boardArea = M*N 
    print(int(boardArea/tileArea))
M,N=map(int,input().split())
solve(M,N)