y=input()
print(sum(x in 'aeiou' or x in '13579' for x in y))