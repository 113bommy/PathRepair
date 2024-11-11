input()
if any([x%2 for x in map(int, input().split())]):
    print("First")
else:
    print("Second")
