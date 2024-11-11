n = int(input())
arr = input().split(" ")
print (len(set([a for a in arr if int(a) != 0])))
