"""
## Name of Prob
A. Reverse a Substring

## Link
https://codeforces.com/contest/1155/problem/A

## Note
Find one string by reverse a substring which lexicographically small

## Input
n
s

## Output
NO

or

YES
transformed str


## Strategy
if given string is lexicographically smallest, answer should return to NO
or just swap a[i:i + 2] which a[i] > a[i + 1], 0 <= i < n
"""

_DEBUG = True
n = int(input())
s = input()


def find_solution(n, a):
    for i in range(0, n - 1):
        if a[i] > a[i + 1]:
            return i + 1, i + 2
    return None


solution = find_solution(n, s)
if not solution:
    print('NO')
else:
    print('YES')
    print(solution[0], solution[1])
