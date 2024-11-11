def degree(x,edges):
    return(len([edge for edge in edges if x in edge]))

def solve(n,x,edges):
    d = degree(x,edges)
    if d <= 1 or n % 2 == 0:
        return 'Ayush'
    return 'Ashish'

numberofcases = int(input())
for _ in range(numberofcases):
    n,x = [int(t) for t in input().split()]
    edges = []
    for _ in range(n-1):
        edges.append([int(t) for t in input().split()])
    print(solve(n,x,edges))