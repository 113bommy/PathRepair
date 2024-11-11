N, M = map(int, input().split())
AB = [[int(x) for x in input().split()] for _ in range(M)]
root = list(range(N+1))
con = [1] * (N+1)

def get_root(x):
    rx = root[x]
    if rx == x:
        return x
    z =  get_root(rx)
    root[x] = z
    return z

def merge(a,b):
  ra = get_root(a)
  rb = get_root(b)
  if ra == rb:
    return 0
  ca = con[ra]
  cb = con[rb]
  if ca > cb:
    root[rb] = ra
    con[ra] += cb
  else:
    root[ra] = rb
    con[rb] += ca
  return ca * cb

def main():
    answer = []
    x = N*(N-1)//2
    for a,b in AB[::-1]:
        answer.append(x)
        x -= merge(a,b)
    for a in answer[::-1]:
        print(a)

if __name__ == '__main__':
    main()