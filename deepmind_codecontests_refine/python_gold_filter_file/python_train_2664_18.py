import sys


def ints_input():
    return [int(i) for i in sys.stdin.readline().strip("\n").split(" ")]


def print_list(arr):
    sys.stdout.writelines(str(x)+" " for x in arr)
    sys.stdout.write("\n")


def fast_input(type=str):
    return type(sys.stdin.readline().strip("\n"))



n = fast_input(int)
ans = "ROYGBIV"
s = "GBIVRO"
ans = ans*(n//7)

if n % 7 == 1:
    ans += 'G'
if n % 7 == 2:
    ans += 'GB'
if n % 7 == 3:
    ans += 'GBI'
if n % 7 == 4:
    ans += 'YGBI'
if n % 7 == 5:
    ans += 'OYGBI'
if n % 7 == 6:
    ans += 'OYGBIV'
print(ans)
