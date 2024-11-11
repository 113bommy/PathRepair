#!/usr/bin/env python3

def main():
    n, k = map(int, input().split())
    arr = [*list(range(k+1, 0, -1)), *list(range(k+2, n+1))]
    
    print(*arr)

if __name__ == "__main__":
    main()

