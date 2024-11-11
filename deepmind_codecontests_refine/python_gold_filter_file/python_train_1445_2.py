"""
セグメント木
"""

INF = 10 ** 20

def main():
  n, q = map(int, input().split())
  
  size = 1
  while size < n:
    size *= 2
  size = size * 2 - 1
  
  seg_tree = [(INF, 0) for _ in range(size)]
  
  def update(a, v):
    ind = (size - 1) // 2 + a
    prea, prev = seg_tree[ind]
    seg_tree[ind] = (a + 1, prev + v)

    while ind > 0:
      ind = (ind - 1) // 2
      ca1, cv1 = seg_tree[ind * 2 + 1]
      ca2, cv2 = seg_tree[ind * 2 + 2]
      if cv1 >= cv2:
        if seg_tree[ind] == (ca1, cv1): break
        seg_tree[ind] = (ca1, cv1)

      else:
        if seg_tree[ind] == (ca2, cv2): break
        seg_tree[ind] = (ca2, cv2)
        
  
  for i in range(q):
    a, v = map(int, input().split())
    update(a - 1, v)
    print(seg_tree[0][0], seg_tree[0][1])

main()
