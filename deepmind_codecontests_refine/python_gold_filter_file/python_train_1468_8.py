n=input()+'b'
print(('NO','YES')[all(x in 'aeioun' or y in 'aeiou' for x,y in zip(n,n[1:]))])