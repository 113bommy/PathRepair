# Author: wizplus
# TIme: 2020-08-25 08:02:10


def main():
  n = int(input())
  nums = list(map(int, input().split()))
  o = sorted(nums)
  p, q = -1, -1
  for i in range(n):
    if nums[i] != o[i]:
      if p == -1:
        p = q = i
      else:
        q = i

  if p == q and q == -1:
    print('yes')
    print(1, 1)
  elif nums[p:q+1] == o[p:q+1][::-1]:
    print('yes')
    print(p+1, q+1)
  else:
    print('no')




if __name__ == "__main__":
  main()

