n = int(input())
numbers = list(map(int, input().split()))
nepnum = 0
for item in numbers:
    nepnum += item % 2
if(nepnum > 0):
    print("First")
else:
    print("Second")
