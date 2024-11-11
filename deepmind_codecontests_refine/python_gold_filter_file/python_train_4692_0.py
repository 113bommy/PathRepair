n = int(input())
X = [int(i) for i in input().split(" ")]
Y = [int(i) for i in input().split(" ")]

for p in range(1, 4):
    print("{:.6f}".format(sum( [abs(a - b) ** p for a, b in zip(X,Y) ] ) ** (1 / p) ) )

print("{:.6f}".format(max( [ abs(a - b) for a, b in zip(X, Y) ] ) ) )
 