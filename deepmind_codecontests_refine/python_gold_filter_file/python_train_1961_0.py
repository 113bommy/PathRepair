n = input()

lst = list(map(int, list(n)))
print(max(sum(lst), lst[0] - 1 + 9 * (len(lst) - 1)))
