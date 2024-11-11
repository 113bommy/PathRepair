#!/usr/bin/env python3

def main():
    try:
        while True:
            n, k = map(int, input().split())
            s = input()
            g = s.index('G')
            t = s.index('T')
            if t < g:
                k = -k
            while 0 <= g < n:
                if s[g] == 'T':
                    print("YES")
                    break
                if s[g] == '#':
                    print("NO")
                    break
                g += k
            else:
                print("NO")

    except EOFError:
        pass

main()
