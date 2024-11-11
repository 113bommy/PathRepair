n,m,k=list(map(int,input().split()))

rows={}

for teeth in range(n):
    row,via=list(map(int,input().split()))
    if row not in rows:
        rows[row]=via
    elif rows[row]>via:
        rows[row]=via

total=sum(rows.values())

print([k,total][total<k])
