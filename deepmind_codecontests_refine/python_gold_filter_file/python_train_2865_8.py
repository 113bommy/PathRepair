#!/usr/bin/env python

# import modules used here -- sys is a very standard one
import sys

# Gather our code in a main() function
def main():
    s = list(input())
    p = list(input())
    ans = 0
    for i in range(0, len(s) - len(p) + 1):
        if s[i : i + len(p)] == p:
            s[i + len(p) - 1] = '#'
            ans += 1
    print(ans)




# Standard boilerplate to call the main() function to begin
# the program.
if __name__ == '__main__':
    main()