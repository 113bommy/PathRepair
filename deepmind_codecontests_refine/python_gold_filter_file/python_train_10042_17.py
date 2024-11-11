tnums = {n * (n + 1) // 2 for n in range(35) }
print(('NO', 'YES')[int(input()) in tnums])
