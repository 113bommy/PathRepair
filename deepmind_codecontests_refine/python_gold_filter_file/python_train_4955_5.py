dict1 = {i-96:chr(i) for i in range(97,123)}

class solution:

    def __init__(self):
        self.temp1 = []
        self.temp2 = []
        self.res1 = []
        self.size = 0
        self.res = 0

    def get_input(self):
        str1 = input()
        str2 = input()
        self.temp1 = list(str1)
        self.temp2 = list(str2)
        
    def compute(self):
        for i in range(len(self.temp1)):
            if self.temp1[i] == self.temp2[i]:
                temp = ord(self.temp1[i])
                self.res1.append(chr(temp))
                
            elif self.temp1[i] >= self.temp2[i]:
                self.res1.append(self.temp2[i])
            else:
                self.res = -1
                
    def result(self):
        if self.res == -1:
            print(-1)
        
        else:
            resultstr = ''.join(map(str,self.res1))
            print(resultstr)
      
    def execute(self):
        self.get_input()
        self.compute()
        self.result()
    
    
def main():
    s1 = solution()
    s1.execute()
    
if __name__ == '__main__':
    main()
        
            
            

      
    
    


    
