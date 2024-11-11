n, h = tuple([int(element) for element in input().split(" ")])
friends = [int(element)-h for element in input().split(" ")]
friends = [1 if element <= 0 else 2 for element in friends]
print(sum(friends))