q,w=map(int,input().split())
count=q
while q//w:
  count+=q//w
  q=q//w+q%w
print(count)