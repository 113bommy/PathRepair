import sys
read = lambda: sys.stdin.readline().strip()
 
for _ in range(int(read())):
    for i in range(int(read())):
        print(i+1, end=" ")
    print()