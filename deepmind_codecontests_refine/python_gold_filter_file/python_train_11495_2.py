#!/usr/bin/env python3
def main():
    
    from sys import stdin, stdout, stderr

    ans = True
    budget = [0, 0]
    
    next(stdin)
    
    for bill in map(int, stdin.readline().split()):
        if bill == 25:
            budget[0] += 1
        elif bill == 50 and budget[0]:
            budget[0] -= 1
            budget[1] += 1
        elif bill == 100 and budget[0] and budget[1]:
            budget[0] -= 1
            budget[1] -= 1
        elif bill == 100 and budget[0] > 2:
            budget[0] -= 3
        else:
            ans = False

    stdout.write("YES\n" if ans else "NO\n")

if __name__ == "__main__":
    main()

