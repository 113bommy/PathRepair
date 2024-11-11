p=list(map(lambda x:len(x),(input().replace('A',' ').replace('E',' ').replace('I',' ').replace('O',' ').replace('U',' ').replace('Y',' ')).split()))
print(max(p)+1 if len(p) else 1)