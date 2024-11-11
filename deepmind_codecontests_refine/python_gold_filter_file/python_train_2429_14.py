import sys
my_file = sys.stdin
#my_file = open("input.txt", "r")
n = int(input())
line = input()
first = [int(i) for i in line[:n]]
second = [int(i) for i in line[n:]]
first.sort()
second.sort()
fort = False
if first[0] <= second[0]:
    for i in range(n):
        if first[i] >= second[i]:
            fort = True
elif first[0] >= second[0]:
    for i in range(n):
        if first[i] <= second[i]:
            fort = True
print("YNEOS"[fort::2])