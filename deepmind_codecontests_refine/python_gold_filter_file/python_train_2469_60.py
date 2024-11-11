class Solution:
    def remove(self,a):
        
        a = sorted(a)
        if (len(a)) % 2 == 0:
            n = int(len(a)/2 - 1)
            return a[n]
        elif len(a) == 1:
            return a[0]
        else:
            m = int((len(a)-1)/2)
            return a[m]
t = Solution()
b = input()
a = [int(x) for x in input().split()]
print(t.remove(a))