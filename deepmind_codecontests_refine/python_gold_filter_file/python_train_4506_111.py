from sys import stdin
input=stdin.readline
for i in range(int(input())):
    list1=[int(x) for x in input().split()]
    print(sum(list1)-1)
