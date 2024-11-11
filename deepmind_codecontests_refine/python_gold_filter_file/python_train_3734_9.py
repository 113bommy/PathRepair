w = input()
print('Yes') if sum([int(w.count(chr(x))%2) for x in range(97,97+26)])==0 else print('No')