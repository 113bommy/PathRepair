class codeforce():
    def __init__(self):
        self.inpn = input()
        self.l = self.lire_nombres()
        self.n = self.lire_nombre()
        # print(l)
       
    def lire_nombres(self):
        ligne = self.inpn.split(' ')
        for ind, ele in enumerate(ligne):
            ligne[ind] = int(ele)
        return ligne

    def lire_nombre(self):
        return int(self.inpn)
    def liste():
        print('12')
        
        
class fmat:
    def __init__(self):
        pass
    def f004NextRound(self, l):
        k, n = l[1], l[0]
        s = 0
        if 1 <= k <= n <= 50:
            code = codeforce()
            vals = code.l
            for ind, ele in enumerate(vals):
                if vals[ind] > 0 and vals[ind] >= vals[k - 1]:
                    s += 1
        print(s)
    def f005DominoPiling(self, l):
        a, b = l[0], l[1]
        
        print((a * b) // 2)
        
    def f006bitplus(self, n):
        
        s = 0
        for i in range(n):
            sta = input().split('X')
            # print(sta)
            for j in range(2):
                
                if sta[j] == '++':
                    s += 1
                elif sta[j] == '--':
                    s -= 1
            
        print(s)
        
        
        
            
            
if __name__ == '__main__':
    inp = codeforce()
    
    fma = fmat()
    
    fma.f006bitplus(inp.n)
    # fmat.f004NextRound(inp.l)

        